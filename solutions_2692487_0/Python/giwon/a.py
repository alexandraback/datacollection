def get_minimum_operations(mote_size, mote_cnt, motes):
    if mote_size == 1:
        return mote_cnt
    motes.reverse()
    op_cnt = 0
    op_cnt_add = 0
    op_cnt_del = 0
    while motes:
        if op_cnt + op_cnt_del >= mote_cnt:
            return mote_cnt

        if mote_size > motes[-1]:
            mote_size += motes[-1]
            motes.pop()
            if op_cnt_del > 0:
                op_cnt_del += 1
                if op_cnt_del == op_cnt_add:
                    op_cnt += op_cnt_add
                    op_cnt_del = 0
                    op_cnt_add = 0
            continue
        elif (2*mote_size-1) > motes[-1]:
            mote_size = 2*mote_size - 1 + motes[-1]
            motes.pop()
            if op_cnt_del == 0:
                op_cnt += 1
            else:
                op_cnt_add += 1
                op_cnt_del += 1
            continue
        else:
            op_cnt_del += 1
            while mote_size <= motes[-1]:
                mote_size = 2*mote_size - 1
                op_cnt_add += 1
            mote_size += motes[-1]
            motes.pop()
    return min(mote_cnt, op_cnt + op_cnt_del)


import sys
#import pdb

fileNamePrefix = sys.argv[1]
fileNameIn = fileNamePrefix + ".in"
fileNameOut = fileNamePrefix + ".out"

fileIn = open(fileNameIn, 'r')
lines = fileIn.readlines()

testcnt = int(lines[0])
idx = 1

fileOut = open(fileNameOut, 'w')

#pdb.set_trace()

for test in range(testcnt):
    line = lines[idx].split(' ')
    idx += 1

    my_mote_size = int(line[0])
    mote_cnt = int(line[1])

    line = lines[idx].split(' ')
    idx += 1
    motes = [int(n) for n in line]
    motes.sort()

    res = get_minimum_operations(my_mote_size, mote_cnt, motes)
    fileOut.write("Case #{0}: {1}\n".format(test + 1, res))
