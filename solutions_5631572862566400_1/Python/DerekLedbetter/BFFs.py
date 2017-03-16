#!/usr/bin/env python3

T = int(input().strip())

for caseNo in range(1, T + 1):
   N = int(input().strip())
   friend = [ int(x) - 1 for x in input().split() ]
   assert len(friend) == N
   assert all(x != y for x, y in enumerate(friend))
   assert all(0 <= x < N for x in friend)

   friendsFor = [ [] for x in range(N) ]
   for x in range(N):
      friendsFor[friend[x]].append(x)
   #print('friend =', friend)
   #print(friendsFor)

   # First, find all loops.
   longestLoop = 2
   length2Loops = []
   checked = [ False ] * N
   for first in range(N):
      slow = fast = first
      firstInLoop = None
      while not checked[fast]:
         slow = friend[slow]
         fast = friend[friend[fast]]
         if slow == fast:
            firstInLoop = slow
            break

      if firstInLoop is not None and not checked[firstInLoop]:
         loopLength = 1
         next = friend[firstInLoop]
         while next != firstInLoop:
            next = friend[next]
            loopLength += 1
         #print('first =', firstInLoop, 'loop length =', loopLength)
         longestLoop = max(longestLoop, loopLength)
         if loopLength == 2:
            length2Loops.append(firstInLoop)

      i = first
      while not checked[i]:
         checked[i] = True
         i = friend[i]
   del checked
   #print('max loop =', longestLoop, '2-loops =', length2Loops)

   pairFriendSum = 0
   for friend1 in length2Loops:
      friend2 = friend[friend1]
      for f in (friend1, friend2):
         distance = { f: 0 }
         uncheckedSet = [ x for x in friendsFor[f] if x not in (friend1, friend2) ]
         for f in uncheckedSet:
            distance[f] = 1
         while uncheckedSet:
            x = uncheckedSet.pop()
            for f in friendsFor[x]:
               uncheckedSet.append(f)
               distance[f] = distance[x] + 1
         #print((friend1, friend2), distance)
         pairFriendSum += max(distance.values()) + 1

   answer = max(longestLoop, pairFriendSum)
   print('Case #{}: {}'.format(caseNo, answer))
