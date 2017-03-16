from common import *

def main(casenum):
    n = readline()

    val = int(n)

    k = len(n)

    steps = [
            0,
            9,
            9 + 9 + 1,
            9 + 99 + 1,
            99 + 99 + 1,
            99 + 999 + 1,
            999 + 999 + 1,
            999 + 9999 + 1,
            9999 + 9999 + 1,
            9999 + 99999 + 1,
            99999 + 99999 + 1,
            99999 + 999999 + 1,
            999999 + 999999 + 1,
            999999 + 9999999 + 1,
            9999999 + 9999999 + 1,
            9999999 + 99999999 + 1,
            99999999 + 99999999 + 1,
            99999999 + 999999999 + 1,
            999999999 + 999999999 + 1,
            999999999 + 9999999999 + 1
        ]

    if k == 1:
        writecase(casenum, val)
        return

    count = sum(steps[:k])

    if n[-1] == '0':
        count += 1
        val -= 1
        n = str(val)

    if len(n) < k:
        writecase(casenum, count)
        return

    if k % 2 == 0:
        front = (n[: k // 2])[::-1]
        back = n[k // 2:]
    else:
        front = (n[: (k - 1) // 2])[::-1]
        back = n[(k - 1) // 2:]

    count += int(front) + int(back)
    if int(front) > 1:
        count += 1

    writecase(casenum, count)

run(main)
