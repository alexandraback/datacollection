
all_fair_nums = []
with open('fair_numbers.txt') as f:
    for line in f:
        all_fair_nums.append(int(line.strip()))


def solve_case(t):
    A, B = [int(s) for s in raw_input().strip().split()]

    ct = 0
    for num in all_fair_nums:
        if num >= A and num <= B:
            ct += 1

    print ("Case #%d: %d" % (t, ct))


T = int(raw_input())
for i in xrange(T):
    solve_case(i + 1)
