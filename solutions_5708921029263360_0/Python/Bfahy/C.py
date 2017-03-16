#!/usr/bin/env python3
import argparse
import math
import logging



def read_input():
    f = open(args.inputfile)
    T = int(f.readline())
    for i in range(T):
        yield f.readline()


def output(n, s, valid):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)
    for i in valid:
        print(" ".join(map(str,i)))
        outfile.write(" ".join(map(str,i)))
        outfile.write("\n")


def all_combs(J,P,S):


    return [(j,p,s) for j in range(1,J+1) for p in range(1,P+1) for s in range(1,S+1)]


def is_valid(outfits, j, p, s, K):

    logging.info("checking {}{}{} against {}".format(j,p,s,outfits))
    logging.info("K {}".format(K))
    jp_count = 0
    ps_count = 0
    js_count = 0
    for j1, p1, s1 in outfits:
        if j1 == j and p1 == p:
            jp_count += 1
        if j1 == j and s1 == s:
            js_count += 1
        if p1 == p and s1 == s:
            ps_count += 1

        logging.info("counts {} {} {}".format(jp_count, js_count, ps_count))

        if jp_count >= K or js_count >= K or ps_count >= K:
            print (j,p,s)
            print (j1,p1,s1)
            print (jp_count, js_count, ps_count)
            return False
    return True



def valid_combs(J,P,S,K):

    valid = []
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,S+1):
               if is_valid(valid, j,p,s,K):
                   logging.debug("adding {} {} {}".format(j,p,s))
                   valid.append((j,p,s))
    return valid

def valid_combs2(J,P,S,K):

    valid = []
    for j in range(J,0,-1):
        for p in range(P,0,-1):
            for s in range(S,0,-1):
               if is_valid(valid, j,p,s,K):
                   logging.debug("adding {} {} {}".format(j,p,s))
                   valid.append((j,p,s))
    return valid


def main():
    for n, case in enumerate(read_input(), start=1):
        logging.info(case)

        J, P, S, K = map(int,case.split())

        print(J*P*S)

        allcombs = all_combs(J, P, S)

        print("all\n", allcombs)
        valid = valid_combs(J,P,S,K)
        valid2 = valid_combs2(J,P,S,K)

        print("valid\n", valid)

        days = len(valid)

        print(len(valid), len(valid2))
        if len(valid) != len(valid2):
            print("WTF TWO WAYS NOT SAME")
            exit(-1)

        output(n, days, valid)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="google code jam 1a 2016 C")
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
    main()
