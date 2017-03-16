def solve(input_file, output_file):
  f = open(input_file, 'r')
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for i in range(num_tests):
    digit_set = set()
    sheep_counter = int(f.readline())
    if sheep_counter == 0:
      o.write('Case #%d: INSOMNIA\n' % (i+1))
      continue
    j = 1
    while len(digit_set) != 10:
      str_num = str(j * sheep_counter)
      digit_set |= set(str_num)
      j += 1
    o.write(('Case #%d: ' + str((j-1) * sheep_counter) + '\n') % (i+1))

solve('A-small-attempt0.in', 'A-small-attempt0.out')
