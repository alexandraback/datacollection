with open("A-small-attempt1.in") as f:
    lines = f.readlines()

outputname = 'outputAsmall1.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def digits(num):
    return len(str(num))

def intpow(num, exponent):
    cur = 1
    for i in range(exponent):
        cur *= num
    return cur

def find_count(num):
    cur = 1
    count = 1
    target = digits(cur) * 10 - 1
    while target < num:
        target = intpow(10, digits(cur)) - 1
        if target > num:
            target = num
        dig = digits(target)
        left = dig / 2
        right = left
        if dig % 2 != 0:
            right += 1

        if left == 0:
            lefttarget = 0
            leftorig = 0
        else:
            lefttarget = int(str(target)[:left][::-1])
            leftorig = int(str(cur)[:left][::-1])

        righttarget = int(str(target)[-right:])
        rightorig = int(str(cur)[-right:])

        extra = 0
        if left > 0:
            extra += 1
        extra += lefttarget - leftorig
        extra += righttarget - rightorig

        count += min(extra, target-cur)
        cur = target


        if target < num:
            cur += 1
            count += 1
    return count

easy = [0] * 1000002
easy[1] = 1
for i in range(2, len(easy)):
    val = 9999999999999
    rev = int(str(i)[::-1])
    if rev < i and digits(i) == digits(rev):
        val = easy[rev]

    easy[i] = min(easy[i-1] + 1, val + 1)

for i in range(cases):
    num = int(lines[linenum])
    linenum += 1

    f.write("Case #" + str(i+1) + ": " + str(easy[num]) + "\n")


f.close()

with open(outputname, 'r') as f:
    print(f.read())
