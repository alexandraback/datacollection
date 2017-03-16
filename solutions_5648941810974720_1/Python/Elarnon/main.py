from collections import Counter

numbers = [
    'ZERO',
    'ONE',
    'TWO',
    'THREE',
    'FOUR',
    'FIVE',
    'SIX',
    'SEVEN',
    'EIGHT',
    'NINE'
]

easy = [['Z'], [], ['W'], [], ['U'], [], ['X'], [], ['G'], []]
harder = [[], ['O'], [], ['H'], [], ['F'], [], ['S'], [], []]

def main(s):
    result = Counter()
    data = Counter(s)

    for i, letters in enumerate(easy):
        if not letters:
            continue
        letter = letters[0]
        nb = data[letter]
        for l in numbers[i]:
            data[l] -= nb
        result[i] = nb
    
    for i, letters in enumerate(harder):
        if not letters:
            continue
        letter = letters[0]
        nb = data[letter]
        for l in numbers[i]:
            data[l] -= nb
        result[i] = nb

    result[9] = data['I']
    data['I'] -= result[9]
    data['N'] -= 2 * result[9]
    data['E'] -= result[9]
    assert(sum(data.values()) == 0)

    out = []
    for i in range(10):
        while result[i] > 0:
            result[i] -= 1
            out.extend(str(i))

    return ''.join(out)

if __name__ == '__main__':
    import sys
    nb = int(sys.stdin.readline())
    for i in range(nb):
        print('Case #{}: {}'.format(i+1, main(sys.stdin.readline().strip())))
