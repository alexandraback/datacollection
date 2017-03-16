#-*- coding: utf-8 -*-
def fractiles(K, C, S):
    rts = []
    if S * C < K:
        return "IMPOSSIBLE"
    else:
        mins = K/C
        if mins * C < K:
            mins += 1

        for i in xrange(mins):
            cnt = 1
            cv = 1
            for j in xrange(C):
                cnt += ((j + i*C)%K) * cv
                cv *= K
            rts.append(cnt)
    return " ".join(map(str, rts))

def deal_input(filename):
    output_name = filename.replace(".in", ".out")
    with open(filename, "r") as fin, open(output_name, "w") as fout:
        all = fin.read().split("\n")
        data_num = int(all[0])
        if data_num != len(all) - 2:
            print "wrong input.\n"
            return
        else:
            for i in xrange(1, data_num+1):
                k,c,s = all[i].split(" ")
                fout.write("Case #%s: %s\n" % (i, fractiles(int(k), int(c), int(s)) ) )


if __name__ == "__main__":
    deal_input("D-large.in")