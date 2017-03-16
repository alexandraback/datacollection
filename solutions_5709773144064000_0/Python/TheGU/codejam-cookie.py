debug = False

with open("B-small-attempt0.in","r") as f:
    with open("out.txt","w") as o:
        count = 0
        for row in f:
            if not count:
                line = row
                count += 1
                continue

            ########################################
            # Solve Problem
            result = ""
            
            c,f,x = list(map(float, row.split()))
            if debug:
                print(c,f,x)
            cookie_rate = 2
            total_time = 0

            if x > c:
                while True:
                    predict = (x/(cookie_rate+f))+(c/cookie_rate)
                    if predict > (x/cookie_rate):
                        result = total_time + (x/cookie_rate)
                        break
                    
                    total_time += c/cookie_rate
                    cookie_rate += f
                    
            else:
                result = x/cookie_rate
            
            ########################################
            # Output
            case_result = "Case #%s: %s" % (count,result)
            if debug:
                print(case_result)
            o.write(case_result+'\n')
            count += 1
