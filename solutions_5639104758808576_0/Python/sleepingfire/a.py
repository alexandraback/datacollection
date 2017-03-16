import sys

#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    N = int(in_file.readline())
    for case_num in range(N):
        sm, au = in_file.readline().strip().split()
        sm = int(sm)

        add, total = 0, 0
        for i in range(sm+1):
            if i > total:
                add += i - total
                total = i
            total += int(au[i])
            #print i, total, add

        print "Case #{}: {}".format(case_num+1, add)

    in_file.close()
