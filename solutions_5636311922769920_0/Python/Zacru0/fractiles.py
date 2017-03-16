from itertools import product


def gen_possible(k, c):
  results = []
  # print(k, c)
  for start in product("GL", repeat=k):
    i = 1
    start = "".join(start)
    old = start
    while i < c:
      i += 1
      new = "".join([start if c == 'L' else 'G'*k for c in old])
      old = new
    # print(start, old)

filename = "D-small-attempt0"
in_filename = filename+".in"
out_filename = filename+".out"
f_in = open(in_filename, 'r')
lines = f_in.readlines()
f_out = open(out_filename, 'w')
for i, line in enumerate(lines[1:]):
  k, c, s = map(int, line.strip().split())
  # gen_possible(k, c)
  l = k**c
  if s == k:
    results = [str(sum(i*(l//(k**j)) for j in range(1, k+1))+1) for i in range(s)]
    result_str = " ".join(results)
  else:
    result_str = "IMPOSSIBLE"
  
  f_out.write("Case #{}: {}\n".format(i+1, result_str))

# GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
# GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
# GGGGGGGGGGGGGGGG
# GGGGGGGGGGGGGGGG
# GGGG
# GGGG
# G
# G
# L
# G
# GGGG
# GGGGGGGGGGGGGGGG
# GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG