
if __name__ == '__main__':
    
    fi = open('B-large.in', 'r')
    fo = open('dance.out', 'w')
    
    n = int(fi.readline())
    
    for i in range(1, n + 1):
        
        num = [int(x) for x in fi.readline().split()]
        g, s, p = num[:3]
        scores = num[3:]
        
        num_pass = 0
        num_can_be_improved = 0
        
        for score in scores:
            # There are only 3 cases (x,x,x), (x+1,x,x) (x+1,x+1,x)
            #    (x,x,x) => (x+1,x,x-1)
            #    (x+1,x,x) => cannot improve highest score
            #    (x+1,x+1,x) => (x+2,x,x)
            
            # ... and oh! must be aware x-1 must greater than or eq 0! thanks test case! ....
            
            x = score / 3
            remain = score % 3
            
            if remain == 0:
                if x >= p: num_pass += 1
                elif x + 1 >= p and x > 0: num_can_be_improved += 1
            elif remain == 1:
                if x + 1 >= p: num_pass += 1
            elif remain == 2:
                if x + 1 >= p: num_pass += 1
                elif x + 2 >= p: num_can_be_improved += 1
        
        num_can_be_improved = min(num_can_be_improved, s)
        ans = num_pass + num_can_be_improved
        
        output = "Case #%d: %d" % (i, ans)
        fo.write("%s\n" % output)
        print output
    
    fi.close()
    fo.close()
        
                    
    
    

