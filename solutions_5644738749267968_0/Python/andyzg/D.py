import copy

def main():
  input = open("input.in", "r").read().split("\n")
  output = open("output.out", "w")

  cases = int(input.pop(0))

  for i in range(1, cases+1):
    N = int(input.pop(0))
    naomi = map(float, input.pop(0).split(" "))
    ken = map(float, input.pop(0).split(" "))
    a, b = solve(naomi, ken)
  
    output.write("Case #" + str(i) + ": " + str(a) + " " + str(b) + "\n")

def solve(naomi, ken):
  deceit = deceitSolve(copy.deepcopy(naomi), copy.deepcopy(ken))
  war = warSolve(copy.deepcopy(naomi), copy.deepcopy(ken))
  
  return (deceit, war)

def greater(naomi, ken):
  for i in range(0, len(naomi)):
    if ken[i] > naomi[i]:
      return False
  return True

def deceitSolve(naomi, ken):
  naomi.sort()
  ken.sort()
  while not greater(naomi, ken):
    ken.pop(len(ken)-1)
    naomi.pop(0)
    if not ken:
      return 0
  return len(ken)

def warSolve(naomi, ken):
  naomi.sort()
  ken.sort()
  init = len(naomi)
  count = 0

  for n in naomi:
    index = 0
    while ken[index] < n and len(ken) >= 1:
      index += 1
      if index >= len(ken):
        break
    if index >= len(ken):
      ken.pop(0)
    else:
      count += 1
      ken.pop(index)    
  return init - count

main()
