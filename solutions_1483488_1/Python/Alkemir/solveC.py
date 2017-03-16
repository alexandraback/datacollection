lines = open('c_small.txt', 'r').read().split('\n')

T = int(lines.pop(0))

for t in range(T):
   (A, B) = map(int, lines[t].split(' '))
   
   count = 0
   recycled = set()
   for x in range(A, B+1):
      #Generar las secuencias
      theseFriends = set()
      if x not in recycled:
         x = str(x)

         for i in range(len(x)):
            new = int(x[i:] + x[:i])
            if (A <= new <= B):
               recycled.add(new)
               theseFriends.add(new)

         if len(theseFriends) > 1:
            count += len(theseFriends)*(len(theseFriends)-1)/2
         
   print 'Case #' + str(t+1) + ': ' + str(count)