package com.db;

import java.sql.Connection;
import java.sql.DriverManager;

public class Mysqlconnection {
	// 属性
	// 定义数据库操作的常量、对象
	// 数据库驱动程序
	private final String DBDRIVER = "com.mysql.jdbc.Driver";
	// 数据库连接地址
	private final String DBURL = "jdbc:mysql://localhost:3306/xgnews";
	// 数据库用户名
	private final String DBUSER = "root";
	// 数据库连接密码
	private final String DBPASSWORD = "xg@adminv587";
	// 声明一个数据库连接对象
	private Connection conn = null;
	// 在构造方法之中连接数据库
	public Mysqlconnection() {
		try {
			// 加载驱动程序
			Class.forName(DBDRIVER);
			// 连接数据库
			conn = DriverManager.getConnection(DBURL, DBUSER, DBPASSWORD);
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	// 返回一个数据库连接
	public Connection getConnection() {
		// / 返回连接对象
		return this.conn;
	}
	// 关闭数据库连接
	public void close() {
		try {
			this.conn.close();
		} catch (Exception e) {
		}
	}
}