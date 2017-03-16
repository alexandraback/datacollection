#-*- coding: utf-8 -*-
def couting_reverse(instr):
    sz = len(instr)
    pos = 0
    current = ""
    rts = 0
    while pos < sz:
        if current != instr[pos]:
            if current:
                rts += 1
            current = instr[pos]
        pos += 1
    if current == "-":
        rts += 1
    return rts

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
                fout.write("Case #%s: %s\n" % (i, couting_reverse(all[i]) ) )


if __name__ == "__main__":
    deal_input("B-large.in")