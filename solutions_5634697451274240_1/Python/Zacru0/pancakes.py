filename = "B-large"
in_filename = filename+".in"
out_filename = filename+".out"
f_in = open(in_filename, 'r')
lines = f_in.readlines()
f_out = open(out_filename, 'w')
for i, line in enumerate(lines[1:]):
  cakes = line.strip()
  if '-' in cakes:
    count = 1
    j = cakes.rfind('-') - 1
    last = '-'
    while j >= 0:
      if cakes[j] != last:
        last = '+' if last == '-' else '-'
        count += 1
      j -= 1
  else:
    count = 0

  f_out.write("Case #{}: {}\n".format(i+1, count))
