import sys
import math

# pow = math.pow

i_name = sys.argv[1]
o_name = sys.argv[2]

with open(i_name) as f:
    with open(o_name, 'w', 10) as g:
        for index, line in enumerate(f.readlines()[1:]):
            line = line[:-1] if line[-1] == '\n' else line
            ##############################################
            out = 1
            
            r, t = [int(a) for a in line.split()]
            print r, t
            out = int((math.sqrt(4 * (pow(r, 2) - r + 2 * t) + 1) - 2 * r + 1)/4)
            print out
            verify = 2*pow(out,2) + out * (2 * r - 1)
            while verify > t:
                out -= 1
                verify = 2*pow(out,2) + out * (2 * r - 1)
            g.write("Case #%d: %d\n" % (index + 1, out))
