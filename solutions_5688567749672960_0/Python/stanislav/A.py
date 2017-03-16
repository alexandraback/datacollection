def run(t):
  N = int(raw_input())
  mem = [N+1] * (N + 1)
  mem[1] = 1
  for i in range(2, N + 1):
    reverse = int(str(i)[::-1])
    if i % 10 == 0 or reverse >= i:
      reverse = i-1
    mem[i] = min(mem[i-1], mem[reverse]) + 1

  print('Case #{}: {}'.format(t, mem[N]))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
