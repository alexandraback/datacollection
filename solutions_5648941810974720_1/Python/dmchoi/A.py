T = int(raw_input())

asdf = [("Z", "ZERO", 0),
 ("W", "TWO", 2),
 ("X", "SIX", 6),
 ("S", "SEVEN", 7),
 ("V", "FIVE", 5),
 ("F", "FOUR", 4), 
 ("R", "THREE", 3),
 ("G", "EIGHT", 8),
 ("O", "ONE", 1),
 ("N", "NINE", 9)]

for t in range(T):

  S = raw_input().strip()

  numbers = []

  for data in asdf:
    while (data[0] in S):
      for c in data[1]:
        S = S.replace(c,"",1)
      numbers.append(data[2]);

  ans = ""
  for i in sorted(numbers):
    ans += str(i)
  
  print "Case #{}: {}".format(t+1, ans)

