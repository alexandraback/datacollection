def Fractiles(k,c,s):
    if k>c*s:
        return ['IMPOSSIBLE']
    else:
        tiles = []
        for n in range(-(-k//c)):
            index = 0
            for i in range(c):
                index += ((n*c+i)%k)*(k**(c-i-1))
            tiles += [index+1]
        return tiles

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
  k, c, s = [int(s) for s in input().split(" ")] 
  tiles = Fractiles(k,c,s)
  outstring = "Case #{}:".format(i)
  for item in tiles:
  	outstring += ' {}'.format(item)
  print(outstring)

  # check out .format's specification for more formatting options