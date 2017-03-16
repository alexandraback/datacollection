#!/usr/bin/python

"""
Author: Morten Lied Johansen - mortenjo@ifi.uio.no

Google CodeJam 2012
Round: 1C
Problem: Diamond inheritance
"""
import collections

import os
import sys
import time
from pprint import pformat
from cStringIO import StringIO
import unittest
import logging
from logging import info, debug, error
from multiprocessing import Pool

# Set up basic logging
logging.basicConfig(format='%(asctime)s %(levelname)s %(message)s', level=logging.INFO)

def yield_line_of_items(reader):
    for x in reader.readline().strip().split():
        yield x

def read_line_of_items(reader):
    return list(yield_line_of_items(reader))

def yield_line_of_ints(reader):
    for i in yield_line_of_items(reader):
        yield int(i)

def read_line_of_ints(reader):
    return list(yield_line_of_ints(reader))

def yield_lines_of_items(reader, num=1):
    for i in range(num):
        yield read_line_of_items(reader)

def read_lines_of_items(reader, num=1):
    return list(yield_lines_of_ints(reader, num))

def yield_lines_of_ints(reader, num=1):
    for i in range(num):
        yield read_line_of_ints(reader)

def read_lines_of_ints(reader, num=1):
    return list(yield_lines_of_ints(reader, num))

def run_in_process(case_solver):
    return case_solver.solve()

class Solver(object):
    def __init__(self, input_name, use_mp=False):
        self.input_name = input_name
        self.output_name = self._make_output_name()
        self.use_mp = use_mp

    def _make_output_name(self):
        basename, ext = os.path.splitext(self.input_name)
        output_name = basename + ".out"
        return output_name

    def open_output(self):
        return open(self.output_name, "w")

    def open_input(self):
        return open(self.input_name, "r")

    def main(self):
        input = self.open_input()
        output = self.open_output()
        self.solve(input, output)

    def solve(self, input, output):
        number_of_cases = read_line_of_ints(input)[0]
        solvers = list()
        for casenr in xrange(number_of_cases):
            solvers.append(CaseSolver(casenr+1, *self.read_case_input(input)))
        if self.use_mp:
            p = Pool()
            solutions = p.map(run_in_process, solvers)
        else:
            solutions = map(run_in_process, solvers)
        for casenr, result in sorted(solutions):
            output.write("Case #%d: %s\n" % (casenr, result))
            output.flush()

    def read_case_input(self, input):
        number_of_classes = read_line_of_ints(input)[0]
        debug("Number of classes: %d", number_of_classes)
        nodes = [Node(0, [])]
        roots = set(range(1, number_of_classes+1))
        for id in xrange(1, number_of_classes+1):
            node_list = read_line_of_ints(input)
            if node_list[0]:
                parent_ids = node_list[1:]
                node = Node(id, parent_ids)
                roots.difference_update(parent_ids)
            else:
                node = Node(id, list())
            nodes.append(node)
        debug("Roots: %r", roots)
        debug("Nodes: %r", nodes)
        return nodes, roots

class Node(object):
    def __init__(self, id, parent_ids):
        self.id = id
        self.parent_ids = parent_ids
        self.visited_by_root = collections.defaultdict(bool)

    def __repr__(self):
        return "<Node(%d, %r)>" % (self.id, self.parent_ids)

class DiamondFound(Exception):
    pass

class CaseSolver(object):
    def __init__(self, casenr, nodes, roots):
        self.casenr = casenr
        self.nodes = nodes
        self.roots = roots

    def solve(self):
        info("Solving case %d", self.casenr)
        result = "No"
        try:
            for id in self.roots:
                self.process(id, id)
        except DiamondFound:
            result = "Yes"
        debug("Result: %s", result)
        return self.casenr, result

    def process(self, id, root):
        node = self.nodes[id]
        for parent_id in node.parent_ids:
            parent = self.nodes[parent_id]
            if parent.visited_by_root[root]:
                raise DiamondFound()
            parent.visited_by_root[root] = True
        for parent_id in node.parent_ids:
            self.process(parent_id, root)

# === Verify correctness of sample data
class SampleTester(unittest.TestCase):
    def setUp(self):
        self.data = open("sample.correct", "r").read()
    def test_sample(self):
        output = StringIO()
        solver = Solver("sample.in")
        input = solver.open_input()
        solver.solve(input, output)
        self.assertEqual(self.data, output.getvalue())

if __name__ == "__main__":
    if "--debug" in sys.argv:
        root_logger = logging.getLogger()
        root_logger.setLevel(logging.DEBUG)
    use_mp = False
    if "--use-mp" in sys.argv:
        use_mp = True
    input_name = sys.argv[1]
    if input_name == "test":
        suite = unittest.TestLoader().loadTestsFromTestCase(SampleTester)
        unittest.TextTestRunner(verbosity=2).run(suite)
    else:
        start = time.time()
        solver = Solver(input_name, use_mp)
        solver.main()
        end = time.time()
        info("Time spent: %s" % time.strftime("%M minutes, %S seconds", time.gmtime(end-start)))
