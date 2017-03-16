order = [0, 2, 6, 8, 4, 3, 5, 7, 1, 9]
mark = list("ZOWRUFXVGI")
words = map(list, ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"])

def solve(chars):
    result = []
    for num in order:
        while mark[num] in chars:
            result.append(num)
            for letter in words[num]:
                chars.remove(letter)
    print chars
    return ''.join(map(str, sorted(result)))

with open('first.in', 'r') as fin:
    with open('first.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            chars = list(fin.readline().rstrip())
            fout.write('Case #{0}: {1}\n'.format(i, solve(chars)))
