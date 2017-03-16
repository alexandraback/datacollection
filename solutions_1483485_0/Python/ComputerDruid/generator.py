#!/usr/bin/env python2
dict = {}

input_str = open("in").read();
output_str = open("out").read();
for i in range(len(input_str)):
	dict[input_str[i]] = output_str[i]

for key in dict:
	print "conversion['%s'] = '%s';"%(key, dict[key])
