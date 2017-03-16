filename = "A-large"
in_filename = filename+".in"
out_filename = filename+".out"
f_in = open(in_filename, 'r')
lines = f_in.readlines()
f_out = open(out_filename, 'w')
for i, line in enumerate(lines[1:]):
  n = int(line.strip())
  if n == 0:
    f_out.write("Case #{}: INSOMNIA\n".format(i+1))
    continue
  seen = set()
  k = 0
  while len(seen) < 10 and k < 1000:
    k += 1
    seen.update(str(n*k))

  if k == 1000:
    print(n)

  f_out.write("Case #{}: {}\n".format(i+1, n*k))
