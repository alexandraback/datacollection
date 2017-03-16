import os
import sys


class Application(object):
    """
    #! /usr/bin/env python
    import template


    class App(template.Application):
        def solve(self):
            pass


    if __name__ == '__main__':
        App()
    """
    def __init__(self):
        self.file = open(sys.argv[1])
        self.out = self.outfile()
        self.numcases = self.numcases()
        self.run()

    @property
    def line(self):
        return self.file.readline().strip()

    @property
    def ints_line(self):
        return [int(x) for x in self.line.split(" ")]

    def numcases(self):
        return int(self.file.readline())

    def outfile(self):
        name, ext = os.path.splitext(self.file.name)
        print "Outputting to %s.out" % name
        return open(name + '.out', 'w')

    def write_case(self, case, line):
        self.out.write("Case #%d: %s\n" % (case, line))

    def run(self):
        for case in range(self.numcases):
            case += 1
            print "\r                    \r%d / %d" % (case, self.numcases),
            sys.stdout.flush()
            self.write_case(case, self.solve())
        print "\r                    \r%d cases written" % (case)
