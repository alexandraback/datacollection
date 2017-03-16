# BendingUnit22; usage: prog_name.py <input.in >output.out

def find_close(val, coins):
	global cache
	key = (val,)+('-',)+tuple(coins)
	if key in cache:
		return cache[key]
	sum_coins = sum(coins)
	if sum_coins > val:
		rets = []
		for i in range(len(coins)):
			now_coins = coins[:]
			del now_coins[i]
			rets.append(find_close(val, now_coins))
	else:
			rets = [val - sum_coins]
	while rets and min(rets) in coin_case:
		rets.remove(min(rets))
	if not rets:
		ret_val = val
	else:
		ret_val = min(rets)
	cache[key] = ret_val
	return ret_val

def find_min(C, D, V, coins):
	global coin_case
	coin_case = []
	for coin in coins:
		for i in range(C):
			coin_case.append(coin)
	min_new_coins = 0
	for val in range(1, V+1):
		now_coins = coin_case[:]
		less = find_close(val, now_coins)
		if less > 0:
			min_new_coins += 1
			for i in range(C):
				coin_case.append(less)
	return min_new_coins

cases = int(raw_input())
for case in range(cases):
	print "Case #%s:" % (case+1),
	global cache
	cache = {}
	C, D, V = map(int, raw_input().split())
	coins = map(int, raw_input().split())
	print find_min(C, D, V, coins)
