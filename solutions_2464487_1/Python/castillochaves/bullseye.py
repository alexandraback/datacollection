import sys

class Bullseye(object):
    def __init__(self, r, t):
        self.r = r
        self.t = t
    def get_n(self):
        a = 2
        b = 2*self.r - 1
        c = -self.t
        delta = b**2 - 4*a*c
        sqdelta = get_sq(delta, delta)
        assert sqdelta ** 2 - delta < 1
        n = (-b + sqdelta)/(2*a)
        return n

def get_bullseye(infile):
    return Bullseye(*[int(x) for x in infile.readline().split()])

def get_sq(number, iteration):
    complement = number / iteration
    if iteration - complement < 1:
        return iteration
    return get_sq(number, (iteration + complement) / 2)

filename = sys.argv[1]
with open(filename)as infile:
    with open('.'.join([filename.split('.')[0], 'out']), 'w') as outfile:
        cases = int(infile.readline())
        for case in range(cases):
            bullseye = get_bullseye(infile)
            circles = bullseye.get_n()
            solution = "Case #%d: %d\n" % (case + 1, circles)
            outfile.write(solution)
