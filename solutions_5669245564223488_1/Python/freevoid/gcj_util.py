'''
Useful functions to read cases and print debugging info in GCJ solutions
'''
import sys

DEBUG = False

with open("/tmp/test.txt", "w") as fp:
    fp.write("HOHOHO")

def dprint(*args, **kwargs):
    indent_level = kwargs.pop('indent', 0)
    indent = '  ' * indent_level
    if DEBUG:
        sys.stderr.write(indent + ' '.join(map(str, args)))
        sys.stderr.write('\n')
        sys.stderr.flush()


def read_ints(fp):
    return map(int, fp.readline().split(' '))


def read_floats(fp):
    return map(float, fp.readline().split(' '))


def read_int(fp):
    return int(fp.readline())
