import math

def custom_range(start=0,stop=None,step=1):
    '''xrange in python 2.7 fails on numbers larger than C longs.
    we write a custom version'''
    if stop is None:
        #handle single argument case. ugly...
        stop = start
        start = 0
    i = start
    while i < stop:
        yield i
        i += step
xrange=custom_range

def main():
    input = open('in', 'r')
    out = open('out', 'w')

    numberOfTests = int(input.next())
    for testCaseN in xrange(1, numberOfTests+1):
        out.write("Case #" + str(testCaseN) + ":")

        k, c, s = map(int, input.next().split())

        for i in xrange(s):
            out.write(" " + str(k**(c-1)*i+1))

        out.write('\n')


if __name__ == "__main__":
    main()
