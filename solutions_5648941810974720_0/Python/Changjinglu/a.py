words = [ "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine" ]
unique_order = [
    ('z', 'zero'),
    ('w', 'two'),
    ('u', 'four'),
    ('x', 'six'),
    ('g', 'eight'),
    ('h', 'three'),
    ('o', 'one'),
    ('f', 'five'),
    ('s', 'seven'),
    ('e', 'nine') ]

word_letter_counts = {}
for word in words:
  counts = {}
  for ch in word:
    counts[ch] = counts.setdefault(ch, 0) + 1
  word_letter_counts[word] = counts

num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
  s = raw_input().strip().lower()
  letter_counts = {}
  for ch in s:
    letter_counts[ch] = letter_counts.setdefault(ch, 0) + 1
  digits = []
  for letter, word in unique_order:
    if letter not in letter_counts:
      continue
    x = letter_counts[letter]
    digit = words.index(word) 
    for i in range(x):
      digits.append(digit)
      for ch, count in word_letter_counts[word].items():
        letter_counts[ch] -= count
  digits.sort()
  result = ''.join(map(str, digits))
  print('Case #%d: %s' % (case_index, result))
