#!/usr/bin/python
import operator, sys

# Password Problem

def get_input_lines(filename):
    file = open(filename, 'r')
    lines = file.readlines()
    file.close()
    n = int(lines[0])
    return n, lines[1:]

def main(infile):
    (cases, lines) = get_input_lines(infile)
    for x in xrange(cases):
        typed, total = [int(i) for i in lines[x*2].split()]
        probs = [float(i) for i in lines[(x*2)+1].split()]
        expected_values = []
        # Keep typing
        p = reduce(operator.mul, probs)
        e = (p * (total + 1 - typed)) + ((1.0 - p) * ((total + 1) * 2 - typed))
        expected_values.append(e)
        # Pressed backspace n times
        for n in xrange(1, typed):
            # Probability all remaining are good
            p = reduce(operator.mul, probs[:typed-n])
            e = (p * ((n * 2) + (total - typed) + 1)) + ((1.0 - p) * ((n * 2) + ((total + 1) * 2) - typed))
            expected_values.append(e)
        # Press enter now
        e = total + 2
        expected_values.append(e)
        print("Case #%d: %0.6f" % (x + 1, min(expected_values)))

if __name__ == '__main__':
    main(sys.argv[1])

