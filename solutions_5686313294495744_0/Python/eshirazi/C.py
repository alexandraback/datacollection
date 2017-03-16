import StringIO
import collections

from hopcroftkarp import HopcroftKarp

from ecodejam.input_parser import *


def solve(case_index):
    graph = collections.defaultdict(set)
    n = read_int()
    next_line()

    words = []

    for i in xrange(n):
        first, second = read_word(), read_word()
        words.append((first, second))
        next_line()
        graph[first + "1"].add(second + "2")

    graph = dict(graph)
    num_firsts = len(set(i[0] for i in words))
    num_seconds = len(set(i[1] for i in words))
    num_match = len(HopcroftKarp(graph).maximum_matching()) / 2
    return str(len(words) - (num_firsts + num_seconds - num_match))

SAMPLE = """
3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC
"""

if __name__ == "__main__":
    set_parsed_input(
        StringIO.StringIO(SAMPLE)
    )
    run_solver(solve)
