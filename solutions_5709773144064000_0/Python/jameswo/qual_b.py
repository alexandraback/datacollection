input = open("B-small-attempt0.in","r")
inputlist = input.readlines()
input.close()

length_input = len(inputlist)
numberofplays = int(inputlist[0])

output = open("B-small-attempt0.out","w+")

case = 1
while (case <= numberofplays):
    game_string = inputlist[case]
    game_list = game_string.split(" ")
    Cost_of_farm = float(game_list[0])
    Farm_generates = float(game_list[1])
    X_win_condition = float(game_list[2])
    
    old_rate = 2.0
    new_rate = 2.0
    time_waited = 0.0
    
    while(True): #the update equation, break out when done

        time_to_win = time_waited + X_win_condition / old_rate #if we just wait from this point
        
        time_to_buy_farm = Cost_of_farm / old_rate
        new_rate = old_rate + Farm_generates
        time_to_win_farm = time_waited + time_to_buy_farm + X_win_condition/new_rate #if we buy a farm
        
        if(time_to_win_farm > time_to_win): #if buying farm slows us down
            output.write("Case #{0}: {1}\n".format(case, time_to_win))
            break
            
        old_rate = new_rate
        time_waited += time_to_buy_farm
    
    case += 1
    
output.close()
