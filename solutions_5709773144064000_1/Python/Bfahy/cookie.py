#!/usr/bin/env python3
import argparse
import logging

parser = argparse.ArgumentParser(description="google code jam cookie")
parser.add_argument("inputfile", type=str, help="input file")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()
outfile = open(args.inputfile + ".out", "w")
if args.verbose:
    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.DEBUG)
    logging.debug("Verbose debuging mode activated")
else:
    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.INFO)


def read_input():
    f = open(args.inputfile)
    T = int(f.readline())
    for i in range(T):
        yield [float(i) for i in f.readline().split()]


def output(n, s):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)


def time_to_win(rate, X):
    logging.info("win in:{}".format(X/rate))

def buy_win(C, F, X, n):
    cookies =0
    rate = 2.0
    t = 0
    for i in range(n):
        t += C/rate
        rate+=F
    answer = t+X/rate
    logging.debug(answer)
    return answer

def buy_win(C, F, X, t):
    cookies =0
    rate = 2.0
    t = 0
    while True:
        t += C/rate
        rate+=F
        yield t+X/rate


def main():
    for n, case in enumerate(read_input(), start=1):
        print(case)
        C, F, X = case
        rate=2.0
        cookies=0
        farms = 0
        g = buy_win(C, F, X, farms)
        print(g)
        # t = next(g)
        # print(t)
        t = X/rate
        for i in g:
            newt = i
            if newt > t:
                break
            else:
                t = newt


        # while True:
        #     farms+=1
        #     newt = buy_win(C, F, X, farms)
        #     if newt > t:
        #         break
        #     else:
        #         t = newt
        output(n, "{:.7f}".format(t))
        #exit()


if __name__ == "__main__":
    main()
