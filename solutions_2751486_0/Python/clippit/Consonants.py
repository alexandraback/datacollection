CONSONANTS = 'bcdfghjklmnpqrstvwxyz'


def is_consonants(str):
    for c in str:
        if c not in CONSONANTS:
            return False
    return True


with open('A-small-attempt0.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    for i in xrange(T):
        name, n = input.pop(0).split(' ', 2)
        n = int(n)
        L = len(name)
        consecutive = 0
        old_index = -1
        for index in xrange(L - n + 1):
            if is_consonants(name[index: index + n]):
                prev = index - old_index - 1
                old_index = index
                next = L - index - n
                consecutive += 1 + prev + next + prev * next
        f.write('Case #%d: %d\n' % (i + 1, consecutive))
