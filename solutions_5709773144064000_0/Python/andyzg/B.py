def solve(C, F, X, R):
  farmTime = C/R
  nextWinTime = X/(R+F)
  winTime = X/R
  time = 0.0
  count = 0
  while winTime > farmTime + nextWinTime:
    time += farmTime
    R += F
    farmTime = C/R
    nextWinTime = X/(R+F)
    winTime = X/R
    count += 1

  if count == 0:
    return winTime
  else:
    return time + winTime
  

def main():
  input = open("input.in", "r").read().split("\n")
  output = open("output.out", "w")

  cases = int(input.pop(0))

  for n in range(0, cases):
    data = map(float, input.pop(0).split(" "))
    ans = solve(data[0], data[1], data[2], 2)
    output.write("Case #" + str(n+1) + ": " + str(ans) + "\n")

main()
