import sys

# special minutes for num times
def update_cakes(cakes, num):
    for i in range(num):
        half = half_num(cakes[i])
        cakes.append(half)
        cakes.append(cakes[i] - half)
    return cakes[num:]

def half_num(num):
    half = num / 2 
    if num % 2 == 1:
        half += 1
    return half

def min_minutes(cakes):
    if len(cakes) == 0:
        return 0
    cakes = sorted(cakes, reverse=True)
    if cakes[0] <= 3:
        return cakes[0]
    if cakes[0] == 4:
        if len(cakes) > 1:
            if cakes[1] > 2:
                return 4
            else:
                return 3
    # special minutes
    m1 = cakes[0]
    for parts_num in range(2, 5):
        if cakes[0] < parts_num:
            break
        # init new cakes
        cakes1 = []
        for i in range(1, len(cakes)):
            cakes1.append(cakes[i])

        avg = cakes[0] / parts_num
        parts = [avg for z in range(parts_num)]
        left = cakes[0] % parts_num
        for i in range(left):
            parts[i] += 1

        for i in range(parts_num):
            cakes1.append(parts[i])

        m1 = min(m1, parts_num - 1 + min_minutes(cakes1))
        #print parts_num, parts

    # no special minutes
    cakes2 = []
    for i in range(len(cakes)):
        if cakes[i] - 1 > 0:
            cakes2.append(cakes[i] - 1)
    m2 = 1 + min_minutes(cakes2)
    return min(m1, m2)
    

#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    N = int(in_file.readline())
    for case_num in range(N):
        D = int(in_file.readline())
        cakes = [int(z) for z in in_file.readline().split()]
        m = min_minutes(cakes)

        print "Case #{}: {}".format(case_num+1, m)

    in_file.close()
