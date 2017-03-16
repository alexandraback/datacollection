#-*- coding: utf-8 -*-
def couting_sheep(N):
    digit = set(range(10))
    if N == 0:
        return "INSOMNIA"
    else:
        s = 0
        while True:
            s += N
            t = s
            while t > 0:
                a = t%10
                t /= 10
                digit -= set([a])
            if not digit:
                break
        return s

def deal_input(filename):
    with open(filename, "r") as fin, open("output.txt", "w") as fout:
        all = fin.read().split("\n")
        data_num = int(all[0])
        if data_num != len(all) - 2:
            print "wrong input.\n"
            return
        else:
            for i in xrange(1, data_num+1):
                fout.write("Case #%s: %s\n" % (i, couting_sheep(int(all[i])) ) )


if __name__ == "__main__":
    deal_input("A-small-attempt1.in")