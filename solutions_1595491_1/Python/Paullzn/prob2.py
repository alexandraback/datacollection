#!/usr/bin/env python
def work(N, S, T, data):
  if len(data) != N:
    print 'Error in data length'
    return
  count = 0
  scount = 0
  for item in data:
    if item == 0:
      if item >= T:
        count += 1
    elif item % 3 == 0:
      if item / 3 >= T:
        count += 1
      elif item / 3 + 1 >= T:
        scount += 1
    elif item % 3 == 1:
      if int(item / 3) + 1 >= T:
        count += 1
    elif item % 3 == 2:
      if int(item / 3) + 1 >= T:
        count += 1
      elif int(item / 3) + 2 >= T:
        scount += 1
  return count + min(scount, S)


def main():
    fin = open('input.dat', 'r')
    fout = open('output.dat', 'w')
    T = int(fin.readline())
    for i in range(T):
      data = []
      for item in fin.readline().split(' '):
        data.append(int(item))
      result = work(data[0], data[1], data[2], data[3:])
      fout.write('Case #{0}: {1}\n'.format(i+1, result))
    return

if __name__ == '__main__':
    main()
