#!/usr/bin/env python3
import argparse
import logging

parser = argparse.ArgumentParser(description="google code jam practice all your base")
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
        blocks = int(f.readline())
        naomi = [float(i) for i in f.readline().split()]
        ken = [float(i) for i in f.readline().split()]
        yield naomi, ken


def output(n, s):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)

def war(n, k):
    logging.debug("war")
    sn = sorted(n)
    sk = sorted(k)

    points = 0
    for np in sn:
        # logging.debug("naomi plays{}".format(np))
        for kp in sk:
            if kp > np:
                logging.debug("ken wins {} > {}".format(kp,np))

                sk.remove(kp)
                break
        else:
            sk.remove(sk[0])
            points+=1


    return points

def dwar(n, k):
    logging.debug("Deceitful war")
    sn = sorted(n)
    sk = sorted(k)
    points = 0
    kenplays = None
    for np in reversed(sn):
        logging.debug("naomi tells {}".format(np))
        for kp in sk:
            if kp > np:
                logging.debug("ken palys thinking {} > {}".format(kp,np))
                kenplays = kp
                sk.remove(kp)
                break
            else:
                logging.debug("ken palys thinking {} he cant beat {}".format(sk[0],np))
                kenplays = sk[0]
                sk.remove(sk[0])
                break

        for dnp in sn:
            if dnp > kenplays:
                points += 1
                logging.debug("naomi plays {} to beat {}".format(dnp,kenplays))
                sn.remove(dnp)
                break
        else:
            logging.debug("naomi plays {} cant beat {}".format(sn[0],kenplays))
            sn.remove(sn[0])



    return points


def main():
    for n, case in enumerate(read_input(), start=1):
        logging.debug(10,"=========== case{} {}".format(n, repr(case)))
        naomi, ken = case
        w = war(naomi, ken)
        d = dwar(naomi, ken)
        output(n, "{} {}".format(d, w))
        #input("wait")

if __name__ == "__main__":
    main()
