INPUT = 'A-large.in'

def last_word(word):
    s = [word[0]]
    for c in word[1:]:
        if c >= s[0]:
            s = [c] + s
        else:
            s.append(c)
    return ''.join(s)

with open(INPUT) as f:
    lines = f.read().split('\n')[1:]

for num, word in enumerate(lines, start=1):
    print('Case #{0}: {1}'.format(num, last_word(word)))