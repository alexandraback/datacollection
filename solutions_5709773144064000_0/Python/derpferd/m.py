import sys

# fpIn = open("ex.in", "r")
# fpOut = open("ex.out", "w")
fpIn = open("small.in", "r")
fpOut = open("small.out", "w")


def raw_input():
    return fpIn.readline().strip()


class Print(object):
    def __init__(self, f):
        self.f = f

    def write(self, text):
        fpOut.write(text)
        self.f.write(text)

def do_test():
    line = raw_input().split()
    C = float(line[0])
    F = float(line[1])
    X = float(line[2])

    c_per_s = 2.0

    t = 0
    c = 0
    while c != X:
        if c < C:
            need = min((X-c), C)
            c += need
            t += need/c_per_s

        if c >= C:
            t_left = (X-c)/c_per_s
            t_new = ((X-c)+C)/(c_per_s+F)
            if t_new < t_left:
                c -= C
                c_per_s += F
            else:
                return format(t+t_left, ".7f")

    return format(t, ".7f")


def main():
    line = raw_input()
    num_tests = int(line)
    for i in range(num_tests):
        print "Case #" + str(i+1) + ": " + do_test()

if __name__ == '__main__':
    if not isinstance(sys.stdout, Print):
        sys.stdout = Print(sys.stdout)
    main()

