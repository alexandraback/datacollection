file = open("B-large.in")
output = open("outputBlarge.txt", "w")

N = int(file.readline())
for i in range(1, N+1):
    [FARM_COST, FARM_GAIN, TARGET] = [float(x) for x in file.readline().split()]
    #C is the cost of a farm
    #F is the gain from  farm
    #X is the number of cookies we need
    #The goal is to minimise the number of seconds
    #The decision of whether or not to buy a farm needs to be made
    #The initial rate is 2 cookies per second
    cookie_rate = 2
    best_time = None
    time_so_far = 0
    while True:
        current_time_to_win = time_so_far + (TARGET/cookie_rate)
        if best_time == None or current_time_to_win < best_time:
            best_time = current_time_to_win
        else: #It is no longer a gain, diminishing returns have occurred
            output.write("Case #" + str(i) + ": " + str(best_time) + "\n")
            break
        #Otherwise buy a farm instead
        time_to_next_farm = FARM_COST / cookie_rate
        time_so_far += time_to_next_farm
        cookie_rate += FARM_GAIN
output.close()       
    
