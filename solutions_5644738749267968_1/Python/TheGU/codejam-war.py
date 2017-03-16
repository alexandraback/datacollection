debug = False
with open("D-large.in","r") as f:
    with open("out.txt","w") as o:
        count = 0
        case = int(f.readline())
        while case-count>0:
            count += 1
            ########################################
            # Solve Problem
            result = ""
            
            block_count = int(f.readline())
            naomi_block = sorted(list(map(float, f.readline().split())))
            ken_block = sorted(list(map(float, f.readline().split())))
            naomi_block_cheat = list(naomi_block)
            ken_block_cheat = list(ken_block)
            if debug:
                print(count, naomi_block)
                print(count, ken_block)

            # Cheat Solution            
            win_cheat_count = 0
            while naomi_block_cheat and ken_block_cheat:
                # eliminate always lose
                while naomi_block_cheat and ken_block_cheat:
                    if naomi_block_cheat[0] < ken_block_cheat[0]:
                        naomi_block_cheat = naomi_block_cheat[1:]
                        ken_block_cheat = ken_block_cheat[:-1]
                    else:
                        break

                #eliminate never win
                while naomi_block_cheat and ken_block_cheat:
                    if naomi_block_cheat[-1] < ken_block_cheat[-1]:
                        naomi_block_cheat = naomi_block_cheat[1:]
                        ken_block_cheat = ken_block_cheat[:-1]
                    else:
                        break             

                # greedy win if possible
                while naomi_block_cheat and ken_block_cheat:
                    if naomi_block_cheat[0] > ken_block_cheat[0]:
                        naomi_block_cheat = naomi_block_cheat[1:]
                        ken_block_cheat = ken_block_cheat[1:]
                        win_cheat_count += 1
                    else:
                        break                     

                #print(count, win_count)
                #print(count, naomi_block)
                #print(count, ken_block)

            # Normal Solution
            win_normal_count = 0
            while naomi_block and ken_block:
                if ken_block[0] > naomi_block[0]:
                    ken_block = ken_block[1:]
                    naomi_block = naomi_block[1:]
                else:
                    ken_block = ken_block[1:]
                    naomi_block = naomi_block[:-1]
                    win_normal_count += 1
                
            result = "%s %s" % (win_cheat_count, win_normal_count)
            
            ########################################
            # Output
            case_result = "Case #%s: %s" % (count,result)
            if debug:
                print(case_result)
            o.write(case_result+'\n')
            
        
