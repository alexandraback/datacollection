numbers = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
order = [(0, 'Z'), (2, 'W'), (6, 'X'), (8, 'G'), (3, 'H'),
         (7, 'S'), (4, 'R'), (5, 'V'), (1, 'O'), (9, 'I')]


t = int(input())

for q in range(t):
    counts = [0] * 10

    s = input()

    letters = {chr(c): 0 for c in range(ord('A'), ord('Z') + 1)}
    for letter in s:
        letters[letter] += 1

    for number, letter in order:
        major_count = letters[letter]
        counts[number] += major_count
        for c in numbers[number]:
            letters[c] -= major_count

    print('Case #{}: '.format(q + 1), end='')
    for digit, count in enumerate(counts):
        print(str(digit) * count, end='')
    print()

