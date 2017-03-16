import math

def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for nt in range(num_tests):
    [K,C,S] = map(int, f.readline().split(' '))
    print "Doing case %d with K: %d, C: %d, S: %d\n" % (nt+1, K, C, S)
    if S*C < K:
      o.write("Case #%d: IMPOSSIBLE\n" % (nt+1))
      continue
    spots_to_check = [1] * (int(math.ceil(float(K)/C)))
    for i in range(K):
      array_index = i / C
      multiplicative = i % C
      spots_to_check[array_index] += i * K ** multiplicative
    o.write("Case #%d: %s\n" % ((nt+1), ' '.join(map(str, list(spots_to_check)))))

def complexify(original_pattern, complexity):
  new_pattern = original_pattern
  for num in range(complexity - 1):
    temp = ''
    for i in range(len(new_pattern)):
      if new_pattern[i] == 'L':
        temp += original_pattern
      else:
        temp += 'G' * len(original_pattern)
    new_pattern = temp
  print new_pattern

solve('D-large.in')