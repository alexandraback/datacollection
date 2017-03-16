#!/usr/bin/env python

def work(left, right):
  count = 0
  for num in range(left, right + 1):
    i = 0
    ret = [] 
    for pos in range(1, len(str(left))):
      new = int(str(num)[pos:] + str(num)[:pos])
      if new > num and new >= left and new <= right and new not in ret:
        count += 1
        i += 1
        ret.append(new) 
  return count


def main():
    fin = open('input.dat', 'r')
    fout = open('output.dat', 'w')
    T = int(fin.readline())
    for i in range(T):
      data = []
      for item in fin.readline().split(' '):
        data.append(int(item))
      print '---------'
      result = work(data[0], data[1])
      fout.write('Case #{0}: {1}\n'.format(i+1, result))
    return

if __name__ == '__main__':
    main()
