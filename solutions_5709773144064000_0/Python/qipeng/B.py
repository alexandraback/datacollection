with open('B-small-attempt0.in') as f:
	cases = int(f.readline())

	for i in range(cases):
		data = [float(x) for x in f.readline().split()]

		speed = 2.0; target = data[2]; cost = data[0]; extra = data[1]; time = 0.0;

		while target > 0:
			t1 = target / speed;
			t2 = cost / speed + target / (speed + extra);

			if (t1 < t2):
				print "Case #%d: %.7f" % (i+1, time + t1)
				break
			else:
				time += cost/speed
				speed += extra