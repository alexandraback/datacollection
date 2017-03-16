#-*- coding: utf-8 -*-

def isok(pos):
    for v in pos:
        if v not in (0,1):
            return False
    return True

def calc_digit(pos, base):
    cv = 1
    rts = 0
    for v in pos:
        rts += v * cv
        cv *= base
    return rts

def parse_to_digit(inv, base):
    rts = []
    cv = inv
    while cv > 0:
        rts.append(cv%base)
        cv /= base
    return rts

def coin_jam(N, J, fout):
    current = 3
    cnt = 0
    dmap = {}
    while True:
        coin = parse_to_digit(current, 2)
        D = len(coin)
        if N <= D:
            break
        sz = 3**(N - D) + 1
        maxv = 3**(N - D + 1) + 1
        c_base = " ".join(map(str, [calc_digit(coin, x) for x in range(2,11)]))
        print N, D, sz, maxv
        while sz < maxv:
            rts = [0] * N
            pos = parse_to_digit(sz, 3)
            for k in xrange(N - D + 1):
                if pos[k] == 2:
                    pos[k] = -1
            print "pos: ", "".join(map(str, pos)), "coin: ", "".join(map(str, coin))

            for k in xrange(N - D + 1):
                for h in xrange(D):
                    rts[k+h] += pos[k] * coin[h]
            if isok(rts):
                rts.reverse()
                rts_str = "".join(map(str, rts))
                if rts_str not in dmap:
                    dmap[rts_str] = 1
                    fout.write(rts_str)
                    fout.write(" ")
                    fout.write(c_base)
                    fout.write("\n")
                    cnt += 1
                    if cnt >= J:
                        return
            sz += 3
        current += 2

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
                fout.write("Case #%s:\n" % i)
                n, j = all[i].split(" ")
                coin_jam(int(n), int(j), fout)


if __name__ == "__main__":
    deal_input("C-small-attempt3.in")