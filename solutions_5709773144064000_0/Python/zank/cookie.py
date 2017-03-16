def calculate(farm_cost, farm_rate, goal):
	count = 0
	rate = 2
	time = 0

	while True:
		#print('Count: ' + str(count))
		#print('Rate: ' + str(rate))

		time_to_goal = (goal - count) / rate
		time_to_farm = max(0, (farm_cost - count) / rate)
		time_to_goal_with_farm = time_to_farm + (goal) / (rate + farm_rate)
		
		#print('Time to goal: ' + str(time_to_goal))
		#print('Time to farm: ' + str(time_to_farm))
		#print('Time to goal with farm: ' + str(time_to_goal_with_farm))

		if time_to_goal < time_to_farm:
			time += time_to_goal
			return time
		else:
			if time_to_goal < time_to_goal_with_farm:
				time += time_to_goal
				return time
			else:
				time += time_to_farm
				count = 0
				rate += farm_rate

n = int(input())
for i in range(n):
	farm_cost, farm_rate, goal = [float(x) for x in input().split(' ')]
	result = calculate(farm_cost, farm_rate, goal)
	print('Case #' + str(i + 1) + ': ' + str(result))