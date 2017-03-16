import sys

T = int(input())
for N in range(1, T + 1):
    out = 'Case #' + str(N) + ': '
    s = input()
    mot = s[0]
    s = s[1:]
    for x in s:
        if x >= mot[0]:
            mot = x + mot
        else:
            mot = mot + x
    out += mot
    out += '\n'
    sys.stdout.write(out)
    sys.stdout.flush()
    sys.stderr.write(out)
    sys.stderr.flush()