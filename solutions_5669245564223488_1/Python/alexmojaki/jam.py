from string import ascii_lowercase as letters
from math import factorial
import re

infile = open('B-large.in')
outfile = open('output.txt', mode='w')


def read_int_list() -> [int]:
    """
    :rtype : [int]
    """
    return list(map(int, infile.readline().split()))


def read_int() -> int:
    """
    :rtype : int
    """
    return int(infile.readline())


for c in range(read_int()):
    N = read_int()
    line = infile.readline()
    words = line.strip().split()
    ans = 1
    full = {}
    lefts = set()
    rights = set()
    inner = set()
    for i in range(len(words)):
        word = words[i]
        left = word[0]
        right = word[-1]
        match = re.match(left+"+(.*?)"+right+"*$", word)
        word_inner = match.group(1)
        if word_inner:
            already = set()
            current = ""
            for letter in word_inner:
                if letter != current:
                    current = letter
                    if letter in already:
                        ans = 0
                        break
                    already.add(letter)
            word_inner = set(word_inner)
            if word_inner & inner:
                ans = 0
                break
            inner |= word_inner

        if left == right:
            if word_inner:
                ans = 0
                break
            full[left] = full.get(left, 0) + 1

        if left != right:
            if left in lefts or right in rights:
                ans = 0
                break
            lefts.add(left)
            rights.add(right)
    if lefts==rights:
        print(line)
        print(c+1)
    if lefts == rights and lefts or inner & lefts or inner & rights or inner & set(full.keys()):
        ans = 0
    if ans != 0:
        free = len(words)
        for letter in letters:
            if letter in lefts and letter in rights:
                free -= 1
        for letter in full:
            ans *= factorial(full[letter])
            ans = ans % 1000000007
            free -= full[letter]
            if not (letter in lefts or letter in rights):
                free += 1
        ans *= factorial(free)
        ans = ans % 1000000007
        print(full, free)

    print("Case #%i: %s" % (c + 1, ans), file=outfile)

infile.close()
outfile.close()
