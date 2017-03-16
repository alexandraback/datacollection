in_file = "A-large.in"
counter = -1
for line in open(in_file, 'r'):
  counter+=1
  if counter == 0:
    continue
  S = line.strip('\n')
  last_word = ""
  for char in S:
    if len(last_word) == 0:
      last_word = char
    else:
      if ord(last_word[0]) <= ord(char):
        last_word = char + last_word
      else:
        last_word = last_word + char
  answer_str = 'Case #' + str(counter) + ': ' + last_word
  print(answer_str)
