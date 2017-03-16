import sys
from collections import Counter, defaultdict

def solve(s):
    counter = Counter(s)
    names = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    letter_to_digits = defaultdict(set)
    for i, name in enumerate(names):
        for c in name:
            letter_to_digits[c].add(i)
    done, result = 0, []
    for _ in range(10):
        letter = next(letter for letter, digits in letter_to_digits.items() if len(digits) == 1)
        digit = letter_to_digits[letter].pop()
        count = counter[letter] // names[digit].count(letter)
        result.extend([digit] * count)
        for c in names[digit]:
            counter[c] -= count
            if digit in letter_to_digits[c]:
                letter_to_digits[c].remove(digit)
    return ''.join(str(d) for d in sorted(result))

output = 'Case #{}: {}'
t = int(input())
for i in range(t):
    s = input()
    print(output.format(i + 1, solve(s)))
