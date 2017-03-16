def the_last_word(S):
  last_word = ''
  for char in S:
    beginning = char + last_word
    end = last_word + char

    last_word = max(beginning, end)

  return last_word

filename = 'A-large'
f = open(filename + '.in', 'r')
o = open(filename + '.out', 'w')

T = int(f.readline())

for t in range(T):
  S = list(f.readline().replace('\n', ''))
  o.write('Case #%d: %s\n' % (t + 1, the_last_word(S)))
