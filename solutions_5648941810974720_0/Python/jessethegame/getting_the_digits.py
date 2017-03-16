from collections import Counter

file = "A-small-attempt0.in"

DIGITS = [
    ["Z", "ZERO", 0],
    ["W", "TWO", 2],
    ["X", "SIX", 6],
    ["G", "EIGHT", 8],
    ["U", "FOUR", 4],
    ["F", "FIVE", 5],
    ["O", "ONE", 1],
    ["H", "THREE", 3],
    ["V", "SEVEN", 7],
    ["I", "NINE", 9],
]

def getting_the_digits(word):
    digits = []
    counter = Counter(word)
    for letter, word, digit in DIGITS:
        count = counter[letter]
        for i in range(count):
            digits.append(digit)
        for letter in set(word):
            counter[letter] -= count

    return ''.join(map(str, sorted(digits)))

with open(file) as handle:
  T = int(handle.readline())

  for t in range(T):
    S = handle.readline().strip()

    print "Case #{}: {}".format(t + 1, getting_the_digits(S))
