T = int(raw_input())
for case in range(T):
	N = int(raw_input())
	naomi = map(float, raw_input().split())
	ken = map(float, raw_input().split())

	k_blocks = list(ken)
	k_blocks.sort()
	war_point = N
	for n_block in naomi:
		for i in range(len(k_blocks)):
			if k_blocks[i] > n_block:
				k_blocks.pop(i)
				war_point -= 1
				break

	deceiful_war_point = 0
	n_blocks = list(naomi)
	k_blocks = list(ken)
	n_blocks.sort(reverse=True)
	k_blocks.sort(reverse=True)
	for n_block in n_blocks:
		top = 0
		for i in range(top, len(k_blocks)):
			if k_blocks[i] < n_block:
				k_blocks.pop(i)
				deceiful_war_point += 1
				top = i
				break

	print "Case #" + str(case+1) + ":", deceiful_war_point, war_point
