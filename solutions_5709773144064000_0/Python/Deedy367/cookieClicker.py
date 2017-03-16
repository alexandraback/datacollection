import sys

def same_row(i,j): return (i/9 == j/9)
def same_col(i,j): return (i-j) % 9 == 0
def same_block(i,j): return (i/27 == j/27 and i%9/3 == j%9/3)


def cookieClicker(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    input_case = f.readline().split(' ')
    input_case = [float(x) for x in input_case]
    cost = input_case[0]
    rate = input_case[1]
    goal = input_case[2]
    curr_rate = 2
    time = goal/curr_rate
    itera = 1
    while True:
      purchase_time = sum([cost/(curr_rate + i*rate) for i in xrange(itera)])
      total_time = purchase_time + goal/(curr_rate + itera*rate)
      if total_time < time:
        time = total_time
      if total_time > time:
        break;
      itera += 1
    soln += 'Case #{0}: {1:.7f}\n'.format(case+1, time)
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = cookieClicker(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

