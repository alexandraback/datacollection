input_file = open('B-small-attempt15.in')
output_file = open('B-small-attempt15.out', 'w') 
nc =  int(input_file.readline())
for t in range(int(nc)):  

    d = int(input_file.readline())
    p = list(map(int, input_file.readline().split()))   
    ans = max(p)   
    n = 2
    while n < ans:
        ans = min(ans, sum([(x - 1) // n for x in p]) + n)
        n += 1

    print('Case #%d: %s' % (t + 1, ans))
    output_file.write('Case #%d: %s\n' % (t + 1, ans))
    
input_file.close()
output_file.close()      
