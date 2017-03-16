input_file = open('D-large.in')
output_file = open('D-large.out', 'w') 
nc =  int(input_file.readline())
for ci in range(1, nc + 1):
    ans = True
    d = input_file.readline().split()
    x = int(d[0])
    r = int(d[1])
    c = int(d[2])
    if x >= 7:
        ans = False
    elif x > r and x > c:
        ans = False
    elif r * c % x != 0:
        ans = False
    elif (x + 1) // 2 > min(r, c):
        ans = False
    elif x in (1, 2, 3):
        ans = True
    elif x == 4:
        ans = min(r, c) > 2
    elif x == 5:
        ans = not(min(r, c) == 3 and max(r, c) == 5)
    elif x == 6:
        ans = min(r, c) > 3   
   
    winner = 'GABRIEL' if ans else 'RICHARD'
       
    print('case #'+str(ci)+': '+winner+'\n')
    
    output_file.write('case #'+str(ci)+': '+winner+'\n')
input_file.close()
output_file.close()      
