f = open('smalllist', 'r')

fass = [int(line) for line in f]

f.close()

f = open('C-large-1.in', 'r')

T = int(f.readline())

for i in range(T):
  A, B = [int(num) for num in f.readline().split()]
  count = len([fas for fas in fass if fas >= A and fas <= B])
  print 'Case #'+str(i+1)+': ' + str(count)
  